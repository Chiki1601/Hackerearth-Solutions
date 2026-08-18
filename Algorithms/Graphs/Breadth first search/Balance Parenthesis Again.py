import sys

def solve():
    input = sys.stdin.readline

    n = int(input())
    s = input().strip()

    # Store node indices according to their bracket.
    opens = []
    closes = []

    for i, ch in enumerate(s):
        if ch == '(':
            opens.append(i + 1)
        else:
            closes.append(i + 1)

    order = []

    # Build an alternating sequence as much as possible.
    # Start with the character that has more/equal elements.
    if len(opens) >= len(closes):
        turn = 0
    else:
        turn = 1

    while opens and closes:
        if turn == 0:
            order.append(opens.pop())
            turn = 1
        else:
            order.append(closes.pop())
            turn = 0

    # Add remaining vertices.
    order.extend(opens)
    order.extend(closes)

    # Output a chain:
    # order[0] - order[1] - order[2] - ... - order[n-1]
    out = []

    for i in range(n - 1):
        out.append(f"{order[i]} {order[i + 1]}")

    sys.stdout.write("\n".join(out))


if __name__ == "__main__":
    solve()
