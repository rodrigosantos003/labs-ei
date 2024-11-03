import com.brunomnsilva.smartgraph.containers.SmartGraphDemoContainer;
import com.brunomnsilva.smartgraph.graph.Edge;
import com.brunomnsilva.smartgraph.graph.Graph;
import com.brunomnsilva.smartgraph.graph.GraphEdgeList;
import com.brunomnsilva.smartgraph.graph.Vertex;
import com.brunomnsilva.smartgraph.graphview.SmartCircularSortedPlacementStrategy;
import com.brunomnsilva.smartgraph.graphview.SmartGraphPanel;
import com.brunomnsilva.smartgraph.graphview.SmartPlacementStrategy;
import javafx.application.Application;
import javafx.scene.Scene;
import javafx.stage.Stage;
import javafx.stage.StageStyle;

public class Program extends Application {
    public static void main(String[] args) {
        launch(args);
    }

    @Override
    public void start(Stage primaryStage) throws Exception {
        Graph<Local, Bridge> g = new GraphEdgeList<>();

        Vertex<Local> vertexA = g.insertVertex(new Local("A"));
        Vertex<Local> vertexB = g.insertVertex(new Local("B"));
        Vertex<Local> vertexC = g.insertVertex(new Local("C"));
        Vertex<Local> vertexD = g.insertVertex(new Local("D"));

        Edge<Bridge, Local> bridgeA = g.insertEdge(vertexA, vertexB, new Bridge("a"));
        Edge<Bridge, Local> bridgeB = g.insertEdge(vertexB, vertexA, new Bridge("b"));
        Edge<Bridge, Local> bridgeC = g.insertEdge(vertexA, vertexC, new Bridge("c"));
        Edge<Bridge, Local> bridgeD = g.insertEdge(vertexC, vertexA, new Bridge("d"));
        Edge<Bridge, Local> bridgeE = g.insertEdge(vertexA, vertexD, new Bridge("e"));
        Edge<Bridge, Local> bridgeF = g.insertEdge(vertexB, vertexD, new Bridge("f"));
        Edge<Bridge, Local> bridgeG = g.insertEdge(vertexD, vertexC, new Bridge("g"));

        ///////////////////////////////////////////////////////////////////////////////////////
        // NOTHING TO DO BELOW THIS LINE

        SmartPlacementStrategy strategy = new SmartCircularSortedPlacementStrategy();
        SmartGraphPanel<Local, Bridge> graphView = new SmartGraphPanel<>(g, strategy);

        Scene scene = new Scene(new SmartGraphDemoContainer(graphView), 800, 800);

        Stage stage = new Stage(StageStyle.DECORATED);
        stage.setTitle("JavaFX SmartGraph Visualization");
        stage.setScene(scene);
        stage.show();

        graphView.init();
    }
}
