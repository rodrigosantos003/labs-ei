using UnityEngine;

public class Shooter : MonoBehaviour
{
    [SerializeField] private GameObject projectile;
    [SerializeField] private float projectileYPosition;
    [SerializeField] private float rateOfFire;

    [SerializeField] private PlayerHealth playerHealth;

    private float _timer = 0;

    public void ShootProjectile()
    {
        Vector3 projectilePosition = new Vector3(transform.position.x, projectileYPosition, transform.position.z);

        Instantiate(projectile, projectilePosition, Quaternion.identity);
    }


    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        _timer += Time.deltaTime;

        if(_timer >= rateOfFire)
        {
            if(projectile.CompareTag("Spikes") || projectile.CompareTag("FireBall"))
            {
                if(playerHealth.Value >= playerHealth.LowValue)
                {
                    ShootProjectile();
                }
            }
            else
            {
                ShootProjectile();
            }

            _timer = 0;
        }
    }
}
