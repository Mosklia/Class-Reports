#include <iostream>
#include <vector>

#include "CGL/vector2D.h"

#include "mass.h"
#include "rope.h"
#include "spring.h"

namespace CGL
{

    Rope::Rope(Vector2D start, Vector2D end, int num_nodes, float node_mass, float k, vector<int> pinned_nodes)
    {
        // TODO (Part 1): Create a rope starting at `start`, ending at `end`, and containing `num_nodes` nodes.
        for (size_t i = 0; i < num_nodes; ++i)
        {
            double t = 1.0 * i / (num_nodes - 1);
            Vector2D position = (1 - t) * start + t * end;

            Mass *mass = new Mass(position, node_mass, false);
            mass->velocity = Vector2D(0, 0);
            masses.push_back(mass);

            if (i >= 1)
            {
                springs.push_back(new Spring(masses[i - 1], mass, k));
            }
        }

        //        Comment-in this part when you implement the constructor
        for (auto &i : pinned_nodes)
        {
            masses[i]->pinned = true;
        }
    }

    void Rope::simulateEuler(float delta_t, Vector2D gravity)
    {
        for (auto &s : springs)
        {
            // TODO (Part 2): Use Hooke's law to calculate the force on a node
            Vector2D temp = s->m2->position - s->m1->position;
            double length = temp.norm();

            Vector2D force = temp.unit() * s->k * (length - s->rest_length);

            s->m2->forces -= force;
            s->m1->forces += force;
        }

        for (auto &m : masses)
        {
            if (!m->pinned)
            {
                // TODO (Part 2): Add the force due to gravity, then compute the new velocity and position
                Vector2D position = m->position;
                m->forces += gravity * m->mass;
                m->velocity += m->forces / m->mass * delta_t;
                m->position += m->velocity * delta_t;

                // TODO (Part 2): Add global damping
            }

            // Reset all forces on each mass
            m->forces = Vector2D(0, 0);
        }
    }

    void Rope::simulateVerlet(float delta_t, Vector2D gravity)
    {
        // simulateEuler(delta_t, gravity);
        // return;

        for (auto &s : springs)
        {
            // TODO (Part 3): Simulate one timestep of the rope using explicit Verlet （solving constraints)
            Vector2D temp = s->m2->position - s->m1->position;
            double length = temp.norm();

            Vector2D force = temp.unit() * s->k * (length - s->rest_length);

            s->m2->forces -= force;
            s->m1->forces += force;
        }

        for (auto &m : masses)
        {
            if (!m->pinned)
            {
                Vector2D temp_position = m->position;
                // TODO (Part 3.1): Set the new position of the rope mass
                m->forces += gravity * m->mass;
                Vector2D acclerate = m->forces / m->mass;

                m->position = m->position + (m->position - m->last_position) + acclerate * delta_t * delta_t;
                m->last_position = temp_position;

                // TODO (Part 4): Add global Verlet damping
                double damping_factor = 0.00005;
                m->position -= damping_factor * (m->position - temp_position);
            }

            m->forces = Vector2D(0, 0);
        }
    }
}
