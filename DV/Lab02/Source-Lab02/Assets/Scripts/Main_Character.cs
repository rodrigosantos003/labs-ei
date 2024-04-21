using UnityEngine;

public class Main_Character : MonoBehaviour
{
    [SerializeField] private float movementSpeed = 7.5f;
    [SerializeField] private float rotationSpeed = 7.5f;
    [SerializeField] private GameObject bulletPrefab;
    [SerializeField] private int bulletForce = 10;


    CharacterController controller;

    // Start is called before the first frame update
    void Start()
    {
        controller = GetComponent<CharacterController>();
    }

    // Update is called once per frame
    void Update()
    {
        MoveCharacter();
        FireBullet();
    }

    // Move the character using the default moving keys (WASD and direction arrows)
    void MoveCharacter()
    {
        float horizontalInput = Input.GetAxis("Horizontal");
        float verticalInput = Input.GetAxis("Vertical");

        Vector3 movement = new Vector3(horizontalInput, 0, verticalInput);
        controller.Move(movement * Time.deltaTime * movementSpeed);

        if (movement.magnitude > 0)
        {
            Quaternion targetRotation = Quaternion.LookRotation(movement);
            transform.rotation = Quaternion.Slerp(transform.rotation, targetRotation, rotationSpeed * Time.deltaTime);
        }
    }

    // Fire a bullet when the space bar is pressed
    void FireBullet()
    {
        if (Input.GetKeyDown(KeyCode.Space))
        {
            Quaternion bulletRotation = Quaternion.Euler(90, transform.eulerAngles.y, 0);
            Vector3 bulletPosition = new Vector3(transform.position.x, transform.position.y + 5, transform.position.z + 2);

            GameObject bullet = Instantiate(bulletPrefab, bulletPosition, bulletRotation);
            Rigidbody rb = bullet.GetComponent<Rigidbody>();
            rb.velocity = transform.TransformDirection(Vector3.forward * bulletForce);
        }
    }
}
