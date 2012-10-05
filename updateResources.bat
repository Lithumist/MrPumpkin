@echo on

rmdir /s /q "Release/resources"
rmdir /s /q "Debug/resources"
rmdir /s /q "MrPumpkin/resources"

xcopy "RESOURCES_MASTER" "Release" /s /e /v
xcopy "RESOURCES_MASTER" "Debug" /s /e /v
xcopy "RESOURCES_MASTER" "MrPumpkin" /s /e /v