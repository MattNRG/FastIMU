#pragma once

#ifndef _F_ICM40609_H_
#define _F_ICM40609_H_

#include "../IMUBase.hpp"
#include "../IMUUtils.hpp"
/*

	ICM40609 REGISTERS

*/
#define ICM40609_SELF_TEST_X_GYRO 0x00
#define ICM40609_SELF_TEST_Y_GYRO 0x01
#define ICM40609_SELF_TEST_Z_GYRO 0x02

// #define ICM40609_X_FINE_GAIN      0x03 // [7:0] fine gain
// #define ICM40609_Y_FINE_GAIN      0x04
// #define ICM40609_Z_FINE_GAIN      0x05
// #define ICM40609_XA_OFFSET_H      0x06 // User-defined trim values for accelerometer
// #define ICM40609_XA_OFFSET_L_TC   0x07
// #define ICM40609_YA_OFFSET_H      0x08
// #define ICM40609_YA_OFFSET_L_TC   0x09
// #define ICM40609_ZA_OFFSET_H      0x0A
// #define ICM40609_ZA_OFFSET_L_TC   0x0B

#define ICM40609_SELF_TEST_X_ACCEL 0x0D
#define ICM40609_SELF_TEST_Y_ACCEL 0x0E
#define ICM40609_SELF_TEST_Z_ACCEL 0x0F

#define ICM40609_SELF_TEST_A      0x10

#define ICM40609_XG_OFFSET_H      0x13  // User-defined trim values for gyroscope
#define ICM40609_XG_OFFSET_L      0x14
#define ICM40609_YG_OFFSET_H      0x15
#define ICM40609_YG_OFFSET_L      0x16
#define ICM40609_ZG_OFFSET_H      0x17
#define ICM40609_ZG_OFFSET_L      0x18
#define ICM40609_SMPLRT_DIV       0x19
#define ICM40609_MPU_CONFIG       0x1A
#define ICM40609_GYRO_CONFIG      0x1B
#define ICM40609_ACCEL_CONFIG     0x1C
#define ICM40609_ACCEL_CONFIG2    0x1D
#define ICM40609_LP_ACCEL_ODR     0x1E
#define ICM40609_WOM_THR          0x1F

#define ICM40609_MOT_DUR          0x20  // Duration counter threshold for motion interrupt generation, 1 kHz rate, LSB = 1 ms
#define ICM40609_ZMOT_THR         0x21  // Zero-motion detection threshold bits [7:0]
#define ICM40609_ZRMOT_DUR        0x22  // Duration counter threshold for zero motion interrupt generation, 16 Hz rate, LSB = 64 ms

#define ICM40609_FIFO_EN          0x23
#define ICM40609_I2C_MST_CTRL     0x24
#define ICM40609_I2C_SLV0_ADDR    0x25
#define ICM40609_I2C_SLV0_REG     0x26
#define ICM40609_I2C_SLV0_CTRL    0x27
#define ICM40609_I2C_SLV1_ADDR    0x28
#define ICM40609_I2C_SLV1_REG     0x29
#define ICM40609_I2C_SLV1_CTRL    0x2A
#define ICM40609_I2C_SLV2_ADDR    0x2B
#define ICM40609_I2C_SLV2_REG     0x2C
#define ICM40609_I2C_SLV2_CTRL    0x2D
#define ICM40609_I2C_SLV3_ADDR    0x2E
#define ICM40609_I2C_SLV3_REG     0x2F
#define ICM40609_I2C_SLV3_CTRL    0x30
#define ICM40609_I2C_SLV4_ADDR    0x31
#define ICM40609_I2C_SLV4_REG     0x32
#define ICM40609_I2C_SLV4_DO      0x33
#define ICM40609_I2C_SLV4_CTRL    0x34
#define ICM40609_I2C_SLV4_DI      0x35
#define ICM40609_I2C_MST_STATUS   0x36
#define ICM40609_INT_PIN_CFG      0x37
#define ICM40609_INT_ENABLE       0x38
#define ICM40609_DMP_INT_STATUS   0x39  // Check DMP interrupt
#define ICM40609_INT_STATUS       0x3A
#define ICM40609_ACCEL_XOUT_H     0x3B
#define ICM40609_ACCEL_XOUT_L     0x3C
#define ICM40609_ACCEL_YOUT_H     0x3D
#define ICM40609_ACCEL_YOUT_L     0x3E
#define ICM40609_ACCEL_ZOUT_H     0x3F
#define ICM40609_ACCEL_ZOUT_L     0x40
#define ICM40609_TEMP_OUT_H       0x41
#define ICM40609_TEMP_OUT_L       0x42
#define ICM40609_GYRO_XOUT_H      0x43
#define ICM40609_GYRO_XOUT_L      0x44
#define ICM40609_GYRO_YOUT_H      0x45
#define ICM40609_GYRO_YOUT_L      0x46
#define ICM40609_GYRO_ZOUT_H      0x47
#define ICM40609_GYRO_ZOUT_L      0x48
#define ICM40609_EXT_SENS_DATA_00 0x49
#define ICM40609_EXT_SENS_DATA_01 0x4A
#define ICM40609_EXT_SENS_DATA_02 0x4B
#define ICM40609_EXT_SENS_DATA_03 0x4C
#define ICM40609_EXT_SENS_DATA_04 0x4D
#define ICM40609_EXT_SENS_DATA_05 0x4E
#define ICM40609_EXT_SENS_DATA_06 0x4F
#define ICM40609_EXT_SENS_DATA_07 0x50
#define ICM40609_EXT_SENS_DATA_08 0x51
#define ICM40609_EXT_SENS_DATA_09 0x52
#define ICM40609_EXT_SENS_DATA_10 0x53
#define ICM40609_EXT_SENS_DATA_11 0x54
#define ICM40609_EXT_SENS_DATA_12 0x55
#define ICM40609_EXT_SENS_DATA_13 0x56
#define ICM40609_EXT_SENS_DATA_14 0x57
#define ICM40609_EXT_SENS_DATA_15 0x58
#define ICM40609_EXT_SENS_DATA_16 0x59
#define ICM40609_EXT_SENS_DATA_17 0x5A
#define ICM40609_EXT_SENS_DATA_18 0x5B
#define ICM40609_EXT_SENS_DATA_19 0x5C
#define ICM40609_EXT_SENS_DATA_20 0x5D
#define ICM40609_EXT_SENS_DATA_21 0x5E
#define ICM40609_EXT_SENS_DATA_22 0x5F
#define ICM40609_EXT_SENS_DATA_23 0x60
#define ICM40609_MOT_DETECT_STATUS 0x61
#define ICM40609_I2C_SLV0_DO      0x63
#define ICM40609_I2C_SLV1_DO      0x64
#define ICM40609_I2C_SLV2_DO      0x65
#define ICM40609_I2C_SLV3_DO      0x66
#define ICM40609_I2C_MST_DELAY_CTRL 0x67
#define ICM40609_SIGNAL_PATH_RESET  0x68
#define ICM40609_MOT_DETECT_CTRL  0x69
#define ICM40609_USER_CTRL        0x6A  // Bit 7 enable DMP, bit 3 reset DMP
#define ICM40609_PWR_MGMT_1       0x6B // Device defaults to the SLEEP mode
#define ICM40609_PWR_MGMT_2       0x6C
#define ICM40609_DMP_BANK         0x6D  // Activates a specific bank in the DMP
#define ICM40609_DMP_RW_PNT       0x6E  // Set read/write pointer to a specific start address in specified DMP bank
#define ICM40609_DMP_REG          0x6F  // Register in DMP from which to read or to which to write
#define ICM40609_DMP_REG_1        0x70
#define ICM40609_DMP_REG_2        0x71
#define ICM40609_FIFO_COUNTH      0x72
#define ICM40609_FIFO_COUNTL      0x73
#define ICM40609_FIFO_R_W         0x74
#define ICM40609_WHO_AM_I_ICM40609 0x75 // Should return 0x70
#define ICM40609_WHOAMI_DEFAULT_VALUE 0x70
#define ICM40609_XA_OFFSET_H      0x77
#define ICM40609_XA_OFFSET_L      0x78
#define ICM40609_YA_OFFSET_H      0x7A
#define ICM40609_YA_OFFSET_L      0x7B
#define ICM40609_ZA_OFFSET_H      0x7D
#define ICM40609_ZA_OFFSET_L      0x7E

#define ICM40609_DEFAULT_ADDRESS 0x68

class ICM40609 : public IMUBase {
public:
	explicit ICM40609(TwoWire& wire = Wire) : wire(wire) {};

	// Inherited via IMUBase
	int init(calData cal, uint8_t address = ICM40609_DEFAULT_ADDRESS) override;

	void update() override;
	void getAccel(AccelData* out) override;
	void getGyro(GyroData* out) override;
	void getMag(MagData* out) override {};
	void getQuat(Quaternion* out) override {};
	float getTemp() override { return temperature; };

	int setGyroRange(int range) override;
	int setAccelRange(int range) override;
	int setIMUGeometry(int index) override { geometryIndex = index; return 0; };

	int setAccelODR(int odr_hz) override;
	int setGyroODR(int odr_hz) override;
	int getAccelODR() override { return currentODR; }
	int getGyroODR() override { return currentODR; }

	int setAccelLPF(int lpf_hz) override;
	int setGyroLPF(int lpf_hz) override;
	int getAccelLPF() override { return currentAccelLPF; }
	int getGyroLPF() override { return currentGyroLPF; }

	void calibrateAccelGyro(calData* cal) override;
	virtual void calibrateMag(calData* cal) override {};

	bool hasMagnetometer() override {
		return false;
	}
	bool hasTemperature() override {
		return true;
	}
	bool hasQuatOutput() override {
		return false;
	}

	String IMUName() override {
		return "ICM-40609";
	}
	String IMUType() override {
		return "ICM40609";
	}
	String IMUManufacturer() override {
		return "InvenSense";
	}
private:
	float aRes = 32.0 / 32768.0;		//ares value for full range (32g) readings
	float gRes = 2000.0 / 32768.0;			//gres value for full range (2000dps) readings
	int geometryIndex = 0;

	int currentODR = 333;
	int currentAccelLPF = 41;
	int currentGyroLPF = 42;

	float temperature = 0.f;
	AccelData accel = { 0 };
	GyroData gyro = { 0 };

	calData calibration;
	uint8_t IMUAddress;

	TwoWire& wire;

	bool dataAvailable(){ return (readByteI2C(wire, IMUAddress, ICM40609_INT_STATUS) & 0x01);}
};
#endif /* _F_ICM40609_H_ */
