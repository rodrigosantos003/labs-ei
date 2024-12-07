package pt.pa.patterns.memento.model;

import java.util.ArrayList;
import java.util.Collection;
import java.util.Date;
import java.util.List;

public class ShoppingCart implements Originator{
    private List<Product> products;

    public ShoppingCart() {
        products = new ArrayList<>();
    }

    public void addProduct(Product p) {
        products.add(p);
    }

    public void reset() {
        products.clear();
    }

    public void removeProduct(Product p) {
        products.remove(p);
    }

    public Collection<Product> getProducts() {
        return products;
    }

    public double getTotal() {
        double total = 0;
        for (Product p : products) {
            total += p.getCost();
        }
        return total;
    }

    @Override
    public String toString() {
        return String.valueOf(products);
    }


    @Override
    public Memento createMemento() {
        return new ShoppingCartMemento(products);
    }

    @Override
    public void setMemento(Memento savedState) {
        try{
            ShoppingCartMemento memento = (ShoppingCartMemento) savedState;

            this.products = memento.products;
        } catch (Exception e){
            System.out.println("ERROR: Could not cast memento");
        }
    }
    
    class ShoppingCartMemento implements Memento{
        private List<Product> products;

        public ShoppingCartMemento(List<Product> products) {
            this.products = new ArrayList<>(products);
        }

        @Override
        public String getDescription() {
            return "";
        }
    }
}
