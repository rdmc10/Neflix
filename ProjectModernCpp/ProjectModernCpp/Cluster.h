#pragma once
#include <crow.h>
#include <cstdint>

using Position = std::pair<float, float>;

class Cluster
{

public:
	Cluster(uint8_t id, Position clusterPosition);

	void AddPoint(Position positionPoint);
	void UpdateClusterPosition();
	void RemovePoints();

	Position GetPosition() const;

private:
	uint8_t m_id;
	std::pair<float, float> m_clusterPosition;
	std::vector<Position> m_points;
};

