#pragma once

#include <string>

class GameObject
{
public:
	GameObject() { m_x = 0.0f; m_y = 0.0f; m_z = 0.0f; }
	~GameObject() {}
	void setName(std::string p_name) { m_name = p_name; }
	void setID(int p_id) { m_id = p_id; }
	void setX(float p_x) { m_x = p_x; }
	void setY(float p_y) { m_y = p_y; }
	void setZ(float p_z) { m_z = p_z; }
	std::string getName() { return m_name; }
	int getID() { return m_id; }
	float getX() { return m_x; }
	float getY() { return m_y; }
	float getZ() { return m_z; }
private:
	std::string m_name;
	int m_id;
	float m_x;
	float m_y;
	float m_z;
};

