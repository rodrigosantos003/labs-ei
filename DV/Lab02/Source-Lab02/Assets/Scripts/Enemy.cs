using TMPro;
using UnityEngine;

public class Enemy : MonoBehaviour
{
    [SerializeField] private int hitPoints = 100;

    // Start is called before the first frame update
    void Start()
    {

    }

    // Update is called once per frame
    void Update()
    {
       
    }

    public void TakeDamage(int damage)
    {
        hitPoints -= damage;

        if(hitPoints <= 0) { 
            Destroy(gameObject);
        }
    }
}
