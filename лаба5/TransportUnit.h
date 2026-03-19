#pragma once


class TransportUnit {
public:
    virtual ~TransportUnit() = default;
    virtual double calculateToll(double distance) const = 0; // ïîëèìîðôíûé ìåòîä
};

