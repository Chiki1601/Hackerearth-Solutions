s = input().strip()
player = {
    1: 'Alice',
    2: 'Bob',
}
 
 
def play(string, start, end, box=None, turn=player[1]):
    if box is None:
        box = []
    if start == end:
        return turn if string[start] in box else 'Tie'
    if string[start] in box or string[end] in box:
        return turn
    flip = player[2] if turn == player[1] else player[1]
    if (string[start + 1] in box and string[end - 1] in box) or string[start] == string[end]:
        return flip
    if string[start] == string[start + 1]:
        return play(string, start, end - 1, box + [string[end]], flip)
    if string[end] == string[end - 1]:
        return play(string, start + 1, end, box + [string[start]], flip)
    if (string[start + 1] in box or turn == player[2]) and string[end - 1] not in box:
        return play(string, start, end - 1, box + [string[end]], flip)
    else:
        return play(string, start + 1, end, box + [string[start]], flip)
 
 
print(play(s, 0, len(s) - 1))
