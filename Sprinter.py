import pydirectinput

pydirectinput.PAUSE = 0.5

for i in range(3):
    pydirectinput.press("shift")

while True:
    pydirectinput.keyDown("shift")
