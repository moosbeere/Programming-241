#include "flow_car.h"
#include "flow_truck.h"
#include "traffic_flow.h"

int main()
{
    RoadSegment segment(1000.0, 60.0); // 1 км, ограничение 60 км/ч
    TrafficFlow flow(segment);

    // Легковые: быстрее разгоняются и тормозят
    flow.addVehicle<FlowCar>("Toyota", 180, 8.0, 10.0);
    flow.addVehicle<FlowCar>("BMW", 220, 10.0, 12.0);

    // Грузовые: медленнее разгон, мягкое торможение
    flow.addVehicle<FlowTruck>("Volvo Truck", 110, 4.0, 6.0);

    const double timeStep = 1.0; // секунды
    const int steps = 20;

    double currentTime = 0.0;
    for (int i = 0; i < steps; ++i)
    {
        flow.simulate(timeStep);
        currentTime += timeStep;
        flow.printState(currentTime);
    }

    return 0;
}
