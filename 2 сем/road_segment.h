#pragma once

// Участок дороги: задаёт границы по координате (length)
// и максимально допустимую скорость на этом участке (speedLimit).
class RoadSegment
{
private:
    double length;      // длина, м
    double speedLimit;  // ограничение скорости, км/ч

public:
    // Ограничиваем входные значения, чтобы не получить отрицательные длину/лимит.
    RoadSegment(double length, double speedLimit)
        : length(length < 0 ? 0.0 : length),
          speedLimit(speedLimit < 0 ? 0.0 : speedLimit)
    {
    }

    // Геттеры используются в симуляции для расчёта целевой скорости и позиционирования.
    double getLength() const { return length; }
    double getSpeedLimit() const { return speedLimit; }
};

