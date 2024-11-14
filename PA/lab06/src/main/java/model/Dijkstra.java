package model;

import com.brunomnsilva.smartgraph.graph.Edge;
import com.brunomnsilva.smartgraph.graph.Graph;
import com.brunomnsilva.smartgraph.graph.Vertex;

import java.util.*;

public class Dijkstra {
    public static DijkstraResult calculateLowestCostPath(Vertex<Airport> source, Graph<Airport, Flight> graph){
        DijkstraResult result = new DijkstraResult();

        Set<Vertex<Airport>> unvisited = new HashSet<>();

        for(Vertex<Airport> vertex : graph.vertices()){
            result.costsTable.put(vertex, Double.POSITIVE_INFINITY);
            result.predecessorsTable.put(vertex, null);
            unvisited.add(vertex);
        }

        result.costsTable.put(source, 0.0);

        while (!unvisited.isEmpty()){
            Vertex<Airport> v = findSmallestCostVertex(unvisited, result.costsTable);
            unvisited.remove(v);

            for(Edge<Flight, Airport> edge: graph.incidentEdges(v)){
                Vertex<Airport> w = graph.opposite(v, edge);

                double newCost = result.costsTable.get(v) + edge.element().getDistance();
                double oldCost = result.costsTable.get(v);

                if(newCost < oldCost){
                    result.costsTable.put(w, newCost);
                    result.predecessorsTable.put(w, v);
                }
            }
        }

        return result;
    }

    public static void calculateLowestCostPathBetweenVertices(Vertex<Airport> source, Vertex<Airport> destination, Graph<Airport, Flight> graph){
        System.out.println("Custo: " + lowestCost(source, destination, graph));
        System.out.println("Caminho: " + lowestCost(source, destination, graph));
    }

    private static double lowestCost(Vertex<Airport> source, Vertex<Airport> destination, Graph<Airport, Flight> graph){
        return calculateLowestCostPath(source, graph).costsTable.get(destination);
    }

    private static List<Vertex<Airport>> lowestCostPath(Vertex<Airport> source, Vertex<Airport> destination, Graph<Airport, Flight> graph){
        List<Vertex<Airport>> path = new ArrayList<>();
        Map<Vertex<Airport>, Vertex<Airport>> predecessors = calculateLowestCostPath(source, graph).predecessorsTable;

        while (!path.contains(source)){
            path.add(0, predecessors.get(path.get(0)));
        }

        return path;
    }

    private static Vertex<Airport> findSmallestCostVertex(Set<Vertex<Airport>> unvisited, Map<Vertex<Airport>, Double> costsTable){
        Vertex<Airport> smallestCostVertex = null;
        double smallestCost = Double.POSITIVE_INFINITY;

        for(Vertex<Airport> v : costsTable.keySet()){
            if(unvisited.contains(v) && costsTable.get(v) < smallestCost){
                smallestCostVertex = v;
                smallestCost = costsTable.get(v);
            }
        }

        return smallestCostVertex;
    }

    static class DijkstraResult{
        private Map<Vertex<Airport>, Double> costsTable;
        private Map<Vertex<Airport>, Vertex<Airport>> predecessorsTable;

        public DijkstraResult() {
            this.costsTable = new HashMap<>();
            this.predecessorsTable = new HashMap<>();
        }

        public Map<Vertex<Airport>, Double> getCostsTable() {
            return costsTable;
        }

        public Map<Vertex<Airport>, Vertex<Airport>> getPredecessorsTable() {
            return predecessorsTable;
        }
    }
}
