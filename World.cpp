#include "World.h"

World::World()
{

}

void World::add(IObject *object)
{
    m_objects.push_back(object);
}

void World::draw(QPainter &painter) const
{
    for(auto it = m_objects.constBegin(); it < m_objects.constEnd(); ++it) {
        (*it)->draw(painter);
    }
}
