import argparse
import serial

if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument('--port', '-p', required=True, help="Serial port number")
    parser.add_argument('--select_output', '-s', choices=['1', '2'], required=True, help="Select hdmi port number")
    args = parser.parse_args()
    try:
        with serial.Serial(port=args.port, baudrate=9600) as ser:
            ser.write(args.select_output.encode())
            print(ser.readline().decode().rstrip())
    except (KeyboardInterrupt, Exception) as ex:
        print(str(ex))
        exit(1)
