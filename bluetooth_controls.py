import sys
import pygame
import serial
import serial.tools.list_ports

pygame.init()

print()
ports = serial.tools.list_ports.comports()
# List available ports
for i in range(len(ports)):
    print(str(i+1) + ': ' + ports[i].device)

# Get selection from user input
choice = input('Select a bluetooth port: ')
while int(choice) < 1 or int(choice) > len(ports):
    print('Please input a value between 1 and ' + str(len(ports)))
    choice = input('Select a bluetooth port: ')

port = ports[int(choice) - 1].device
print('Connecting to ' + port + '...')
# Connect to serial port
ser = serial.Serial(port, 9600)
print('Connection established.')
print('Use arrow keys to control robot')

# Send keydown and keyup events over serial connection
while True:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            sys.exit()
        elif event.type == pygame.KEYDOWN:
            print(event.key)
            ser.write(bytes(str(event.key) + ',' + 'd' + '\n', 'utf-8'))
        elif event.type == pygame.KEYUP:
            ser.write(bytes(str(event.key) + ',' + 'u' + '\n', 'utf-8'))