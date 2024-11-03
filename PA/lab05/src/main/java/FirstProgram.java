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

@SuppressWarnings("removal")
public class FirstProgram extends Application {
    @Override
    public void start(Stage primaryStage) throws Exception {

        Graph<Character, Integer> graph = new GraphEdgeList<>();

        // TODO: create graph structure
        Vertex<Character> a = graph.insertVertex('a');
        Vertex<Character> b = graph.insertVertex('b');
        Vertex<Character> c = graph.insertVertex('c');
        Vertex<Character> d = graph.insertVertex('d');
        Vertex<Character> e = graph.insertVertex('e');
        Vertex<Character> f = graph.insertVertex('f');
        Vertex<Character> g = graph.insertVertex('g');

        graph.insertEdge(a, b, 6);
        graph.insertEdge(b, c, 2);
        graph.insertEdge(c, d, 30);
        graph.insertEdge(d, e, 10);
        graph.insertEdge(d, f, 22);
        graph.insertEdge(f, g, 8);
        graph.insertEdge(f, e, 15);
        graph.insertEdge(e, g, 50);
        graph.insertEdge(g, a, 11);

        ///////////////////////////////////////////////////////////////////////////////////////
        // STUDENTS -> NOTHING TO DO BELOW THIS LINE

        SmartPlacementStrategy strategy = new SmartCircularSortedPlacementStrategy();
        SmartGraphPanel<Character, Integer> graphView = new SmartGraphPanel<>(graph, strategy);

        Scene scene = new Scene(new SmartGraphDemoContainer(graphView), 800, 800);

        Stage stage = new Stage(StageStyle.DECORATED);
        stage.setTitle("JavaFX SmartGraph Visualization");
        stage.setScene(scene);
        stage.show();

        graphView.init();

    }


    public static void main(String[] args) {
        launch(args);
    }
}
