package model;

import com.brunomnsilva.smartgraph.graph.Edge;
import com.brunomnsilva.smartgraph.graph.Graph;
import com.brunomnsilva.smartgraph.graph.Vertex;

import java.util.*;

public class Dijkstra {
    public static DijkstraResult calculateLowestCostPath(Vertex<Airport> source, Graph<Airport, Flight> graph){
        if (source == null) {
            throw new IllegalArgumentException("Source vertex cannot be null.");
        }

        DijkstraResult result = new DijkstraResult();
        Set<Vertex<Airport>> unvisited = new HashSet<>();

        for(Vertex<Airport> vertex : graph.vertices()){
            result.costsTable.put(vertex, Double.MAX_VALUE);
            result.predecessorsTable.put(vertex, null);
            unvisited.add(vertex);
        }

        result.costsTable.put(source, 0.0);

        while (!unvisited.isEmpty()){
            Vertex<Airport> v = findSmallestCostVertex(unvisited, result.costsTable);
            if (v == null) break;

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
        System.out.println("Caminho: " + lowestCostPath(source, destination, graph));
    }

    private static double lowestCost(Vertex<Airport> source, Vertex<Airport> destination, Graph<Airport, Flight> graph){
        return calculateLowestCostPath(source, graph).costsTable.get(destination);
    }

    private static List<Vertex<Airport>> lowestCostPath(Vertex<Airport> source, Vertex<Airport> destination, Graph<Airport, Flight> graph){
        List<Vertex<Airport>> path = new ArrayList<>();
        Map<Vertex<Airport>, Vertex<Airport>> predecessors = calculateLowestCostPath(source, graph).predecessorsTable;

        Vertex<Airport> current = destination;
        while (current != null && !current.equals(source)) {
            path.add(0, current);
            current = predecessors.get(current);
        }
        if (current != null) {
            path.add(0, source);
        }


        return path;
    }

    private static Vertex<Airport> findSmallestCostVertex(Set<Vertex<Airport>> unvisited, Map<Vertex<Airport>, Double> costsTable){
        Vertex<Airport> smallestCostVertex = null;
        double smallestCost = Double.MAX_VALUE;

        for(Vertex<Airport> v : costsTable.keySet()){
            if(unvisited.contains(v) && costsTable.get(v) < smallestCost){
                smallestCostVertex = v;
                smallestCost = costsTable.get(v);
            }
        }

        return smallestCostVertex;
    }

    private static class DijkstraResult{
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
