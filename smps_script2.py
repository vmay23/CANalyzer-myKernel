from RsNgx import *
import time
import os

os.environ['PYTHONPATH'] = 'C:/Users/F86450C/.platformio/python3/'
os.system('Echo "Teste"')



# =========================================================================================================
#              Discovering which is the method is used to control the NGP804 POWER SUPPLY                =
# =========================================================================================================
def CheckAttachedInstrument():
    # Use the instr_list string items as resource names in the RsNgx constructor
    print("\n\n")
    print("===========================================================================")
    print("              Let's show all attached devices in your laptop!")
    print("===========================================================================")
    instr_list = RsNgx.list_resources('?*')
    print(instr_list)
    print("___________________________________________________________________________")
    print("\n")

    protocol = "USB0"
    device_attached = instr_list[0]

    if device_attached.find(protocol) == -1:
        print("Please, make sure the R&D NP804 is connect in your laptop!\n")
    else:
        # print("You are attached via USB per following device: \t" + device_name)
        print("You are attached via USB per following device: \n")

        # Open the session
        # driver = RsNgx('TCPIP::192.168.56.101::HISLIP', True, True, "SelectVisa='rs', Simulate=True")
        driver1 = RsNgx(device_attached, True, True, "Simulate=False")
        #driver1.display.window.text.set_data("My Greetings to you ...")
        device_features = driver1.utilities.query_str('*IDN?')

        driver2 = RsNgx.from_existing_session(driver1)

        print(f"'{device_features}'")
        print(f' Instrument serial name:  {driver1.utilities.instrument_serial_number}')
        print(f' RsNgx package version :  {driver1.utilities.driver_version}')
        print(f' Instrument full name  :  {driver1.utilities.full_instrument_model_name}')
        print(f' Instrument firmware   :  {driver1.utilities.instrument_firmware_version}')
        print(f' Visa manufacturer     :  {driver1.utilities.visa_manufacturer}')
        print(f' Instrument installed options: {",".join(driver1.utilities.instrument_options)}')

        # Close the session
        driver1.close()

        return device_attached


# _________________________________________________________________________________________________________


def PowerSupplyAction(dev, request):
    driver1 = RsNgx(dev, True, True, "Simulate=False")

    if request == str('RESET'):
        print("ACTION ---> The SMPS will be reset")
        driver1.utilities.reset()

    # Close the session
    driver1.close()


def ChangeOutputState(dev, out_channel: int, voltage: float, current: float, time_sleep: float, sts: int):
    driver1 = RsNgx(dev, True, True, "Simulate=False")

    if out_channel == 1:
        print("\n")
        print("Channel 1 has been selected...")
        driver1.instrument.select.set(out_channel)
        if sts == 1:
            print("Setting " + str(voltage) + " volts...")
            driver1.source.voltage.level.immediate.set_amplitude(voltage)
            print("Setting " + str(current) + " amperes...")
            time.sleep(time_sleep)
            driver1.source.current.level.immediate.set_amplitude(current)
            print("Turning the output-1 ON")
            driver1.output.set_select(True)
            print("Enabling the power supply to be active")
            driver1.output.general.set_state(True)
            print("\n")
            time.sleep(5)
            driver1.instrument.select.set(1)
            measurement = driver1.read()
            print(f'Measured values Output 1: {measurement.Voltage} V, {measurement.Current} A')
        elif out_channel == 2:
            print("\n")
            print("Channel 1 has been selected...")
            driver1.instrument.select.set(out_channel)
            if sts == 1:
                print("Setting " + str(voltage) + " volts...")
                driver1.source.voltage.level.immediate.set_amplitude(voltage)
                print("Setting " + str(current) + " amperes...")
                time.sleep(time_sleep)
                driver1.source.current.level.immediate.set_amplitude(current)
                print("Turning the output-1 ON")
                driver1.output.set_select(True)
                print("Enabling the power supply to be active")
                driver1.output.general.set_state(True)
                print("\n")
                driver1.instrument.select.set(1)
        elif sts == 0:
            driver1.output.set_select(False)



#def Data_SMPS:
    #measurement = driver1.read()
    #print(f'Measured values Output 1: {measurement.Voltage} V, {measurement.Current} A')


if __name__ == '__main__':
    #constant
    ACTIVE = 1
    NOT_ACTIVE = 0

    #power supply setup
    channel = 1
    channel_state = ACTIVE
    voltage_level = 13.00
    current_level =  5.00
    time_to_wait  =   1.5

    #initialization
    device = CheckAttachedInstrument()
    PowerSupplyAction(device, 'RESET')
    ChangeOutputState(device, channel, voltage_level, current_level, time_to_wait, channel_state)
    #Data_SMPS()
