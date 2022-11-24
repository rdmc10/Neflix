#include "MovieCategory.h"

MovieCategory::MovieCategory(const MovieCategory& movieCategory)
	: m_id(movieCategory.m_id)
	, m_name(movieCategory.m_name)
{
}

MovieCategory::MovieCategory(const uint32_t& id, const std::string& name)
	: m_id(id)
	, m_name(name)
{
}

void MovieCategory::SetId(const uint32_t& id)
{
	m_id = id;
}

void MovieCategory::SetName(const std::string& name)
{
	m_name = name;
}

uint32_t MovieCategory::GetId() const
{
	return m_id;
}

std::string MovieCategory::GetName() const
{
	return m_name;
}