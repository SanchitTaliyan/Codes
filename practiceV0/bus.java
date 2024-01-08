#pragma once

class Bus : public Vehicle {
private:
	const VehicleSize size = VehicleSize::bus;
	static int numOfVehicles;
public:
	Bus() : Vehicle("B" + std::to_string(numOfVehicles)) { ++numOfVehicles; };
	Bus(std::string numberPlate) : Vehicle(numberPlate) { ++numOfVehicles; };;
	virtual VehicleSize getSize() const;
	virtual ~Bus();
};
