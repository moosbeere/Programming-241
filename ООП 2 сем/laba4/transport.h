#ifndef TRANSPORT_UNIT_H
#define TRANSPORT_UNIT_H

class TransportUnit {
public:
  
    virtual double calculateToll(double distance) const = 0;

    virtual ~TransportUnit() {}
};

#endif 
