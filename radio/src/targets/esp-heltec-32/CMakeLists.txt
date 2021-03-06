set(CPU_FAMILY ESP32)
set(ARCH ESP32)
set(LUA NO)
add_definitions(-DEEPROM_VARIANT=${EEPROM_VARIANT} -DLCD_I2C)
set(SDCARD YES)
set(HAPTIC NO)
set(EEPROM SPIFLASH)
set(GUI_DIR 128x64)
set(NAVIGATION_TYPE 9x)
set(TARGET_DIR esp-heltec-32)
set(FIRMWARE_DEPENDENCIES ${FIRMWARE_DEPENDENCIES} 9x_bitmaps)
set(PPM_LIMITS_SYMETRICAL YES)
set(PXX1 NO)

set(FLAVOUR esp32-heltec)

add_definitions(-DPCBESP_HELTEC_32 -DPPM_PIN_SERIAL -DAUDIO_DUAL_BUFFER)
add_definitions(-DAUDIO -DVOICE -DVARIO)
add_definitions(-DEEPROM_VARIANT=0)
add_definitions(-DSOFTWARE_VOLUME)

set(GUI_SRC
  ${GUI_SRC}
  model_input_edit.cpp
  model_mix_edit.cpp
  model_display.cpp
  radio_diagkeys.cpp
  radio_diaganas.cpp
  view_telemetry.cpp
  view_about.cpp
  view_channels.cpp
  )

if(GVARS)
  set(GUI_SRC
    ${GUI_SRC}
    model_gvars.cpp
    )
endif()

set(FIRMWARE_TARGET_SRC
  ${FIRMWARE_TARGET_SRC}
  board.cpp
  ../common/esp32/drivers/oled_driver_i2c.cpp  
  )

set(TARGET_SRC
  ${TARGET_SRC}
  )

set(SRC
  ${SRC}
  debug.cpp
  )
