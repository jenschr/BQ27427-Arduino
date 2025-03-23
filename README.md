Inspired by https://github.com/sparkfun/SparkFun_BQ27441_Arduino_Library

Based on Zephyr bq274xx driver: https://github.com/zephyrproject-rtos/zephyr/tree/main/drivers/sensor/ti/bq274xx
Current Arduino adaptation is based on FreeRTOS.

Datasheet: https://www.ti.com/product/BQ27427

Contributions and improvements welcome!
I2C commands are described here: https://www.ti.com/lit/ug/sluucd5/sluucd5.pdf


ABOUT Chem IDs:

​The Texas Instruments BQ27427 is a single-cell battery fuel gauge that utilizes the Impedance Track™ algorithm to provide accurate battery capacity measurements. This gauge comes pre-programmed with three selectable chemistry profiles, each identified by a unique Chemistry ID (ChemID):​
 - ChemID 0x3230: Corresponds to a 4.2V lithium-ion cell.​
 - ChemID 0x1202: Corresponds to a 4.35V lithium-ion cell.​
 - ChemID 0x3142: Corresponds to a 4.4V lithium-ion cell.​

These ChemIDs are defined in the Zephyr project's sensor bindings for the BQ27427:​
 - BQ27427_CHEM_ID_A: 0x3230​
 - BQ27427_CHEM_ID_B: 0x1202​
 - BQ27427_CHEM_ID_C: 0x3142​

When configuring the BQ27427 for your application, it's essential to select the ChemID that matches the nominal voltage of your lithium-ion battery to ensure accurate fuel gauging. For more detailed information, you can refer to the BQ27427 product page on Texas Instruments' website. ​