from gpiozero import Motor

left_motor = Motor(forward=17, backward=19)
right_motor = Motor(forward=23, backward=22)

def main(args=None):
    try:
        left_motor.forward(speed=1)
        right_motor.forward(speed=1)
    finally:
        left_motor.stop()
        right_motor.stop()

if __name__ == '__main__':
    main()