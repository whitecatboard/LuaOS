#
# Component Makefile
#

ifdef CONFIG_LUA_RTOS_LUA_USE_STEPPER

COMPONENT_SRCDIRS := . 
COMPONENT_ADD_INCLUDEDIRS := .
COMPONENT_PRIV_INCLUDEDIRS := 

else

COMPONENT_SRCDIRS :=
COMPONENT_ADD_INCLUDEDIRS :=

endif