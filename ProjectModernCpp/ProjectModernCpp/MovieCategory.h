#pragma once
#include <cstdint>
#include <string>
class MovieCategory
{
public:
	MovieCategory() = default;
	MovieCategory(const MovieCategory& movieCategory);
	MovieCategory(const uint32_t& id, const std::string& name);
	void SetId(const uint32_t& id);
	void SetName(const std::string& name);
	uint32_t GetId() const;
	std::string GetName() const;

private:
	uint32_t m_id;
	std::string m_name;
};