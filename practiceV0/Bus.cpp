#include "stdafx.h"
#include "Bus.h"

int Bus::numOfVehicles = 0;

VehicleSize Bus::getSize() const {
	return size;
}

Bus::~Bus() {
}
