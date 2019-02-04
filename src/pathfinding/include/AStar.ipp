
namespace Pathfinding
{
    template<typename T, std::size_t D>
    AStar<T, D>::AStar() : openSet([](const Base::Vertex<T, D>& lhs, const Base::Vertex<T, D>& rhs){return lhs.lessCost(rhs);})
    {
    }

    template <typename T, std::size_t D>
    std::set<Base::Vertex<T, D>> AStar<T, D>::search(Base::Vertex<T, D> start, const Base::Vertex<T, D>& goal, std::set<Base::Edge<T, D>>& edges)
    {
        openSet.clear();
        closedSet.clear();
        predecessorMap.clear();

        start.setActualCost(0.0);
        start.updateHeuristicCost(goal);

        openSet.insert(start);

        while(!openSet.empty())
        {
            auto current = *openSet.begin();
            if(current == goal) return constructPath(current);
            
            closedSet.insert(current);
            std::cout << "CURRENT: " << current.getPoint() << std::endl;
            openSet.erase(current);

            auto connections = getNeighbourConnections(current, edges);
            for(auto& connection : connections)
            {
                // std::cout << "CONNECTION >>> from: " << connection.getFrom().getPoint() << " to: " << connection.getTo().getPoint();
                auto neighbour = connection.getOther(current);
                if(closedSet.find(neighbour) != std::end(closedSet)) continue;
                
                double calculatedActualNeighbourCost = current.getActualCost() + current.calculateCost(neighbour);
                double totalHeuristicCostNeighbour = calculatedActualNeighbourCost + current.calculateCost(goal);

                auto it = openSet.find(neighbour);
                if(it != std::end(openSet))
                {
                    if(it->getHeuristicCost() <= totalHeuristicCostNeighbour) continue;
                    openSet.erase(it);
                }
                neighbour.setActualCost(calculatedActualNeighbourCost);
                neighbour.setHeuristicCost(totalHeuristicCostNeighbour);

                auto result = predecessorMap.insert({neighbour, current});
                if(!result.second)
                {
                    if(result.first->first.getHeuristicCost() > neighbour.getHeuristicCost())
                    {
                        predecessorMap.erase(result.first);
                        predecessorMap.insert({neighbour, current});
                    }
                }
                it = openSet.find(neighbour);
                if(it == std::end(openSet)) openSet.insert(neighbour);
            }
        }
        return {};
    }

    template <typename T, std::size_t D>
    std::set<Base::Vertex<T, D>> AStar<T, D>::getNeighbours(const Base::Vertex<T, D>& vertex, std::set<Base::Edge<T, D>>& edges)
    {
        std::set<Base::Vertex<T, D>> result;
        for(const auto& edge : edges)
        {
            if(vertex == edge.getFrom())
            {
                result.insert(edge.getTo());
            }
        }
        return result;
    }

    template <typename T, std::size_t D>
    std::set<Base::Edge<T,D>> AStar<T, D>::getNeighbourConnections(const Base::Vertex<T, D>& vertex, std::set<Base::Edge<T, D>>& edges)
    {
        std::set<Base::Edge<T,D>> result;
        auto neighbours = getNeighbours(vertex, edges);
        for(const auto& neighbour : neighbours) result.insert(Base::Edge<T, D>(vertex, neighbour));
        return result;
    }

    template <typename T, std::size_t D>
    std::set<Base::Vertex<T, D>> AStar<T, D>::constructPath(const Base::Vertex<T, D>& vertex)
    {
        auto it = predecessorMap.find(vertex);
        std::set<Base::Vertex<T, D>> path;
        if(it != std::end(predecessorMap)) path = constructPath(it->second);
        path.insert(vertex);
        return path;
    }
}