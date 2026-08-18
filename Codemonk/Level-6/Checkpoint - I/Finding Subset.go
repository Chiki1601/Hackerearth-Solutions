package main

import (
	"bufio"
	"fmt"
	"math/bits"
	"math/rand"
	"os"
	"sort"
	"strconv"
	"strings"
	"time"
)

var rng = rand.New(rand.NewSource(time.Now().UnixNano()))

// gcd returns gcd(a, b).
func gcd(a, b uint64) uint64 {
	for b != 0 {
		a, b = b, a%b
	}
	return a
}

// mulMod computes (a * b) % mod safely.
// Since Ai <= 1e10, this is more than sufficient.
func mulMod(a, b, mod uint64) uint64 {
	hi, lo := bits.Mul64(a, b)

	// For our constraints, hi < mod.
	_, rem := bits.Div64(hi, lo, mod)
	return rem
}

// powMod computes a^e % mod.
func powMod(a, e, mod uint64) uint64 {
	result := uint64(1)

	for e > 0 {
		if e&1 != 0 {
			result = mulMod(result, a, mod)
		}
		a = mulMod(a, a, mod)
		e >>= 1
	}

	return result
}

// Deterministic Miller-Rabin for uint64.
// These bases are deterministic for 64-bit integers.
func isPrime(n uint64) bool {
	if n < 2 {
		return false
	}

	smallPrimes := []uint64{2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}

	for _, p := range smallPrimes {
		if n == p {
			return true
		}
		if n%p == 0 {
			return false
		}
	}

	// n - 1 = d * 2^s
	d := n - 1
	s := 0

	for d&1 == 0 {
		d >>= 1
		s++
	}

	bases := []uint64{
		2,
		325,
		9375,
		28178,
		450775,
		9780504,
		1795265022,
	}

	for _, a := range bases {
		if a%n == 0 {
			continue
		}

		x := powMod(a%n, d, n)

		if x == 1 || x == n-1 {
			continue
		}

		composite := true

		for r := 1; r < s; r++ {
			x = mulMod(x, x, n)

			if x == n-1 {
				composite = false
				break
			}
		}

		if composite {
			return false
		}
	}

	return true
}

// Pollard-Rho factor finder.
func pollardRho(n uint64) uint64 {
	if n%2 == 0 {
		return 2
	}

	if n%3 == 0 {
		return 3
	}

	for {
		c := rng.Uint64()%(n-1) + 1
		x := rng.Uint64()%(n-2) + 2
		y := x

		var d uint64 = 1

		for d == 1 {
			// f(x) = x*x + c (mod n)
			x = (mulMod(x, x, n) + c) % n

			y = (mulMod(y, y, n) + c) % n
			y = (mulMod(y, y, n) + c) % n

			if x > y {
				d = gcd(x-y, n)
			} else {
				d = gcd(y-x, n)
			}
		}

		if d != n {
			return d
		}
	}
}

// factor recursively factors n into primes.
func factor(n uint64, factors *[]uint64) {
	if n == 1 {
		return
	}

	if isPrime(n) {
		*factors = append(*factors, n)
		return
	}

	d := pollardRho(n)

	factor(d, factors)
	factor(n/d, factors)
}

// Returns the signature of a number.
//
// Example:
// 12 = 2^2 * 3^1
// signature = "2^2,3^1"
//
// Complement:
// "2^1,3^2"
func getSignatures(n uint64) (string, string) {
	var factors []uint64
	factor(n, &factors)

	sort.Slice(factors, func(i, j int) bool {
		return factors[i] < factors[j]
	})

	// Count prime exponents.
	type pair struct {
		p uint64
		e int
	}

	var grouped []pair

	for _, p := range factors {
		if len(grouped) == 0 || grouped[len(grouped)-1].p != p {
			grouped = append(grouped, pair{p: p, e: 1})
		} else {
			grouped[len(grouped)-1].e++
		}
	}

	var signature strings.Builder
	var complement strings.Builder

	for _, item := range grouped {
		e := item.e % 3

		// Exponent is divisible by 3.
		if e == 0 {
			continue
		}

		if signature.Len() > 0 {
			signature.WriteByte(',')
			complement.WriteByte(',')
		}

		signature.WriteString(strconv.FormatUint(item.p, 10))
		signature.WriteByte('^')
		signature.WriteString(strconv.Itoa(e))

		// Complement exponent:
		// 1 -> 2
		// 2 -> 1
		comp := 3 - e

		complement.WriteString(strconv.FormatUint(item.p, 10))
		complement.WriteByte('^')
		complement.WriteString(strconv.Itoa(comp))
	}

	return signature.String(), complement.String()
}

func main() {
	in := bufio.NewReaderSize(os.Stdin, 1<<20)
	out := bufio.NewWriterSize(os.Stdout, 1<<20)
	defer out.Flush()

	var n int
	fmt.Fscan(in, &n)

	// Count how many times every signature occurs.
	count := make(map[string]int)

	// We only need to factor each distinct input value once.
	signatureCache := make(map[uint64]string)

	for i := 0; i < n; i++ {
		var x uint64
		fmt.Fscan(in, &x)

		sig, ok := signatureCache[x]

		if !ok {
			sig, _ = getSignatures(x)
			signatureCache[x] = sig
		}

		count[sig]++
	}

	answer := 0

	// Empty signature means perfect cube.
	// We can select at most one perfect cube.
	if count[""] > 0 {
		answer++
	}

	// Process all non-cube signatures.
	visited := make(map[string]bool)

	for sig, cnt := range count {
		if sig == "" || visited[sig] {
			continue
		}

		_, complement := getSignaturesFromSignature(sig)

		otherCnt := count[complement]

		if cnt > otherCnt {
			answer += cnt
		} else {
			answer += otherCnt
		}

		visited[sig] = true
		visited[complement] = true
	}

	fmt.Fprintln(out, answer)
}

// Given a signature such as:
// "2^1,3^2"
//
// Returns:
// original = "2^1,3^2"
// complement = "2^2,3^1"
func getSignaturesFromSignature(sig string) (string, string) {
	if sig == "" {
		return "", ""
	}

	parts := strings.Split(sig, ",")

	var complement strings.Builder

	for i, part := range parts {
		if i > 0 {
			complement.WriteByte(',')
		}

		pos := strings.LastIndexByte(part, '^')

		prime := part[:pos]
		exp, _ := strconv.Atoi(part[pos+1:])

		comp := 3 - exp

		complement.WriteString(prime)
		complement.WriteByte('^')
		complement.WriteString(strconv.Itoa(comp))
	}

	return sig, complement.String()
}
