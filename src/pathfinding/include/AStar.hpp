#ifndef A_STAR_HPP
#define A_STAR_HPP

#include <set>
#include <map>
#include <mutex>
#include <functional>

#include <Edge.hpp>

namespace Pathfinding
{
    template <typename T, std::size_t D>
    class AStar
    {
        public:
        std::set<Base::Vertex<T, D>> search(Base::Vertex<T, D> start, const Base::Vertex<T, D>& goal, std::set<Base::Edge<T, D>>& edges);
        AStar();

        private:
        std::set<Base::Vertex<T, D>> constructPath(const Base::Vertex<T, D>& vertex);
        std::set<Base::Vertex<T, D>> getNeighbours(const Base::Vertex<T, D>& vertex, std::set<Base::Edge<T, D>>& edges);
        std::set<Base::Edge<T, D>> getNeighbourConnections(const Base::Vertex<T, D>& vertex, std::set<Base::Edge<T, D>>& edges);

        std::set<Base::Vertex<T, D>, std::function<bool (const Base::Vertex<T, D>&, const Base::Vertex<T, D>&)>> openSet;
        std::set<Base::Vertex<T, D>> closedSet;
        std::map<Base::Vertex<T, D>, Base::Vertex<T, D>> predecessorMap;
    };
}

#include "AStar.ipp"

#endif //A_STAR_HPP