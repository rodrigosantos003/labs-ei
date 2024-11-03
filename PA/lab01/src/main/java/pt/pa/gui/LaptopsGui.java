package pt.pa.gui;

import com.google.gson.Gson;
import com.google.gson.reflect.TypeToken;
import javafx.geometry.Insets;
import javafx.geometry.Pos;
import javafx.scene.control.*;
import javafx.scene.image.Image;
import javafx.scene.image.ImageView;
import javafx.scene.layout.*;
import javafx.scene.text.Font;
import javafx.scene.text.FontWeight;
import javafx.scene.text.Text;
import pt.pa.model.Laptop;
import pt.pa.model.Review;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.lang.reflect.Type;
import java.util.ArrayList;
import java.util.List;

/**
 * @author amfs
 */
public class LaptopsGui extends BorderPane {

    private static final String DATA_PATH = "src/main/resources/laptop_reviews.json";

    private static final String BANNER_PATH = "src/main/resources/header_banner.png";

    List<Laptop> laptops;

    ListView<Laptop> listViewLaptops;

    private VBox mainContent;


    public LaptopsGui() throws Exception {
        try {
            this.laptops = loadData();
            initializeComponents();
        } catch (FileNotFoundException e) {
            throw new Exception("Unable to initialize Laptops GUI");
        }
    }

    public void initializeComponents() throws FileNotFoundException {
        ImageView banner = loadThumbnailImage();
        setTop(banner);

        listViewLaptops = new ListView<>();
        listViewLaptops.getItems().addAll(laptops);

        // Set a custom cell factory to display each laptop
        listViewLaptops.setCellFactory(param -> new ListCell<Laptop>() {
            @Override
            protected void updateItem(Laptop laptop, boolean empty) {
                super.updateItem(laptop, empty);

                if (empty || laptop == null) {
                    setText(null);
                } else {
                    setText(laptop.getDisplayName());
                }
            }
        });

        setLeft(listViewLaptops);

        mainContent = new VBox();

        listViewLaptops.getSelectionModel().selectedItemProperty().addListener((observable, oldValue, newValue) -> {
            if (newValue != null) {
                mainContent.getChildren().clear();

                Label heading = new Label("Laptop Information");
                heading.setFont(Font.font("Arial", FontWeight.BOLD, 25));

                String infoText = "Display Name: " + newValue.getDisplayName() + " " +
                        "Release Date: " + newValue.getReleaseDate() + " " +
                        "CPU: " + newValue.getCpu() + " " +
                        "RAM: " + newValue.getRam() + " " + "\n" +
                        "SSD: " + newValue.getSsd() + "\n";

                Label info = new Label(infoText);

                Separator separator = new Separator();

                Label reviewsHeading = new Label("Reviews:");

                List<Review> reviews = newValue.getReviews();

                mainContent.setPadding(new Insets(15));
                mainContent.setSpacing(10);
                mainContent.getChildren().addAll(heading, info, separator, reviewsHeading);

                for(Review review : reviews){
                    String detailsText = "User: " + review.getUserName() + " " +
                            "Rating: " + review.getRating() + "\n" +
                            "Comment: " + review.getComment() + "\n";

                    Label details = new Label(detailsText);

                    mainContent.getChildren().add(details);
                }
            }
        });

        setCenter(mainContent);

    }

    /**
     * Load the data  contain on json file specified on DATA_PATH.
     * @return list of Lapstop contained on the file
     * @throws FileNotFoundException in case of the file not exists
     */
    private List<Laptop> loadData() throws FileNotFoundException {

        Gson gson = new Gson();

        Type arrayListType = new TypeToken<ArrayList<Laptop>>() {
        }.getType();

        return gson.fromJson(new FileReader(DATA_PATH), arrayListType);
    }

    /**
     * create an Image View from the image file specified on BANNER_PATH
     * @return the Image View created from the file specified on BANNER_PATH
     * @throws FileNotFoundException in case the file not exists
     */
    ImageView loadThumbnailImage() throws FileNotFoundException {
        FileInputStream inputStream = new FileInputStream(BANNER_PATH);
        Image image = new Image(inputStream);
        return new ImageView(image);
    }

}