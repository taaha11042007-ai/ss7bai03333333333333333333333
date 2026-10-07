#include <stdio.h>

struct DeviceUnoptimized {
    char deviceName[20];
    double measuredPower;
    int deviceID;
    float voltage;
    int status;
    float current;
    int operatingMinutes;
};

struct DeviceOptimized {
    double measuredPower;
    float voltage;
    float current;
    int deviceID;
    int operatingMinutes;
    int status;
    char deviceName[20];
};

struct ElectricalInfo {
    float voltage;
    float current;
    double measuredPower;
};

struct DeviceStatus {
    int deviceID;
    int status;
    int operatingMinutes;
};

struct SmartDeviceNested {
    char deviceName[20];
    struct ElectricalInfo electrical;
    struct DeviceStatus device;
};

int main() {
    struct DeviceUnoptimized oldDevice;
    struct DeviceOptimized device;

    struct SmartDeviceNested nestedDevice;

    float calculatedPower;
    double powerDifference;
    double differencePercent;
    double energyKWh;

    printf("=== SMART HOME IOT - STRUCT MEMORY ANALYSIS ===\n\n");

    printf("Kich thuoc struct chua toi uu: %zu bytes\n",
           sizeof(struct DeviceUnoptimized));

    printf("Kich thuoc struct da toi uu: %zu bytes\n",
           sizeof(struct DeviceOptimized));

    printf("Kich thuoc struct long nhau: %zu bytes\n",
           sizeof(struct SmartDeviceNested));

    printf("\n=== NHAP THONG TIN THIET BI ===\n");

    printf("Nhap ma thiet bi: ");
    scanf("%d", &device.deviceID);

    printf("Nhap ten thiet bi: ");
    scanf(" %19[^\n]", device.deviceName);

    printf("Nhap trang thai (0-Tat, 1-Bat): ");
    scanf("%d", &device.status);

    printf("Nhap dien ap U (V): ");
    scanf("%f", &device.voltage);

    printf("Nhap dong dien I (A): ");
    scanf("%f", &device.current);

    printf("Nhap cong suat do duoc P (W): ");
    scanf("%lf", &device.measuredPower);

    printf("Nhap thoi gian hoat dong (phut): ");
    scanf("%d", &device.operatingMinutes);

    if (device.voltage <= 0 ||
        device.current < 0 ||
        device.operatingMinutes < 0) {

        printf("\nLOI: Du lieu cam bien khong hop le.\n");
        printf("Dien ap phai > 0, dong dien >= 0, thoi gian >= 0.\n");

        return 0;
    }

    if (device.status != 0 && device.status != 1) {
        printf("\nLOI: Trang thai thiet bi khong hop le.\n");
        printf("Trang thai chi duoc nhap 0 hoac 1.\n");

        return 0;
    }

    calculatedPower = device.voltage * device.current;

    powerDifference = device.measuredPower - calculatedPower;

    if (powerDifference < 0) {
        powerDifference = -powerDifference;
    }

    if (calculatedPower > 0) {
        differencePercent =
            (powerDifference / calculatedPower) * 100.0;
    } else {
        differencePercent = 0;
    }

    energyKWh =
        device.measuredPower *
        (device.operatingMinutes / 60.0) /
        1000.0;

    printf("\n=== PHAN TICH AN TOAN THIET BI ===\n");

    printf("Ma thiet bi: %d\n", device.deviceID);
    printf("Ten thiet bi: %s\n", device.deviceName);
    printf("Trang thai: %s\n",
           device.status == 1 ? "BAT" : "TAT");

    printf("Dien ap: %.2f V\n", device.voltage);
    printf("Dong dien: %.2f A\n", device.current);

    printf("Cong suat do duoc: %.2f W\n",
           device.measuredPower);

    printf("Cong suat tinh toan U x I: %.2f W\n",
           calculatedPower);

    printf("Do sai lech: %.2f%%\n",
           differencePercent);

    if (differencePercent > 5.0) {
        printf("CANH BAO: Cam bien cong suat bao sai lech.\n");
    } else {
        printf("Cong suat cam bien nam trong nguong cho phep.\n");
    }

    if (device.current > 30.0 ||
        device.measuredPower > 6600.0) {

        printf("CANH BAO: QUA TAI NGUY HIEM.\n");
    } else {
        printf("Tai dien nam trong nguong an toan.\n");
    }

    if (device.status == 0 &&
        device.current > 0.05) {

        printf("CANH BAO: RO RI DIEN HOAC TAI AN.\n");
    } else {
        printf("Khong phat hien ro ri dien hoac tai an.\n");
    }

    printf("Thoi gian hoat dong: %d phut\n",
           device.operatingMinutes);

    printf("Dien nang tieu thu: %.4f kWh\n",
           energyKWh);

    return 0;
}