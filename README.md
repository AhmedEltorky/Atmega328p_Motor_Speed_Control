# Atmega328p Motor Speed Control

### Atmega328p Motor Speed Control by Two PWM Modes:
### 1- Fast PWM mode.
### 2- Phase Correct PWM mode.
### You will notice that the Fast PWM freq. is double the Phase Correct PWM freq. but the speed of two motors is the same, that because the duty cycle (Average Power) is the same in the two modes.
### the duty_cycle = Ton / (Ton +Toff) * 100
### duty cycle represented in OCRxA register if you need 50% duty cycle then the OCRxA value will be:
### OCRxA = duty_cycle * 256 / 100 ==> OCRxA = 50 * 256 / 100 = 128

## Design:

![design](https://user-images.githubusercontent.com/26473614/54697483-53566980-4b36-11e9-8a7d-d022a5831dc1.png)

## PWM waves frequencies:

![Freq](https://user-images.githubusercontent.com/26473614/54697485-53ef0000-4b36-11e9-97c4-40d44fc7c83c.PNG)
