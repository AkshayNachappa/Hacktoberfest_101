import random

SWITCHPLAYER = {"X": "O", "O": "X"}


def flip(board):
    ret = [""]*6
    for col in board:
        for x in range(6):
            if x < len(col):
                ret[x] += col[x]
            else:
                ret[x] += " "
    return ret[::-1]


def wind(game):
    for cols in game:
        if "XXXX" in cols:
            return "X"
        elif "OOOO" in cols:
            return "O"
    cp = flip(game)
    for rows in cp:
        if "XXXX" in rows:
            return "X"
        elif "OOOO" in rows:
            return "O"

    build = []
    for cY in (1, -1):
        maxY = 0 if cY == 1 else 5

        for startY in range(maxY + (cY * 2), maxY - cY, -cY):
            x = 0
            y = startY
            build.append("")
            while x < 7 and 0 <= y < 6:
                build[-1] += cp[y][x]
                x += 1
                y += cY

        for startX in range(1, 4):
            x = startX
            y = maxY
            build.append("")
            while x < 7 and 0 <= y < 6:
                build[-1] += cp[y][x]
                x += 1
                y += cY

    for b in build:
        if "XXXX" in b:
            return "X"
        elif "YYYY" in b:
            return "Y"

    if not possible(game):
        return "S"


def disp(gdisp):
    print("--1-2-3-4-5-6-7--")
    for row in flip(gdisp):
        print("|", " ".join(row), "|")
    print("-"*14 + "---")


def possible(b):
    return [x for x in range(7) if len(b[x]) != 6]


def simulate(game, playas):  # Make an X move
    candidates = dict.fromkeys(possible(game), 0)
    if len(candidates) == 1:
        return list(candidates)[0]

    for _ in range(10000):
        playon = game[:]
        fm = None
        play = playas
        i = 0
        while not wind(playon):
            i += 1
            move = random.choice(possible(playon))
            if fm is None:
                fm = move
            playon[move] += play
            play = SWITCHPLAYER[play]

        result = wind(playon)

        if result == playas:
            candidates[fm] += 1
            if i == 1:  # this move wins the game
                return fm
        elif result == SWITCHPLAYER[playas]:
            candidates[fm] -= 1
            if i == 2:  # this move fails to block an imminent win
                candidates[fm] -= 2000
    return max(candidates, key=candidates.get)


grid = [""] * 7  # grid stored on its side
while True:
    player = input(
        "Computer is X, enter who goes first x/o >>> ").upper().strip()
    if len(player) > 0 and player[0] in ("X", "O"):
        player = player[0]
        break
    else:
        print("Bad input")
while True:
    if player == "X":
        print("Thinking...")
        move = simulate(grid, "X")
    else:
        while True:
            try:
                move = int(
                    input(f"Player {player}, please make a move. >>> ")) - 1
                break
            except ValueError:
                print("Please enter a column between 1 and 7 inclusive.")

    grid[move] += player  # do the move
    player = SWITCHPLAYER[player]

    disp(grid)

    if result := wind(grid):
        if result in "XO":
            print(f"### Player {result} wins!!! ###")
        if result == "S":
            print("### No winner this time. ###")
        break
