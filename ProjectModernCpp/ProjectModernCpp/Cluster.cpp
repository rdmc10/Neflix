#include "Cluster.h"

Cluster::Cluster(uint8_t id, Position clusterPosition)
	: m_id(id)
	, m_clusterPosition(clusterPosition)
{
}

void Cluster::AddPoint(Position positionPoint) {
	m_points.push_back(positionPoint);
}

void Cluster::UpdateClusterPosition() {
	Position sumOfPositions = { 0.f, 0.f };
	auto& [x, y] = sumOfPositions;
	for (const auto& point : m_points)
	{
		x += point.first;
		y += point.second;
	}
	if (x != 0 && y != 0)
		m_clusterPosition = { x / m_points.size(), y / m_points.size() };
}

void Cluster::RemovePoints() {
	m_points.clear();
}

Position Cluster::GetPosition() const {
	return m_clusterPosition;
}