using System.Collections;
using System.Collections.Generic;
using TMPro;
using UnityEngine;

public class PlayerController : MonoBehaviour
{
    private bool _moving = false;
    private CharacterController _controller;

    [SerializeField] private float runSpeed = 5f;
    [SerializeField] private TextMeshProUGUI text;
    private int _collectedItems = 0;
    private float _time = 30f;

    // Start is called before the first frame update
    void Start()
    {
        _controller = GetComponent<CharacterController>();
        StartCoroutine(Countdown());
    }

    // Update is called once per frame
    void Update()
    {
        // Check for movement commands
        if (Input.GetAxis("Vertical") != 0 || Input.GetAxis("Horizontal") != 0)
        {
            GetComponent<Animator>().SetTrigger("TriggerRunning");
            _moving = true;
        }
        else
        {
            GetComponent<Animator>().SetTrigger("TriggerIdle");
            _moving = false;
        }
    }

    private void FixedUpdate()
    {
        // Calculate movement direction
        if(_moving)
        {
            _moving = false;
            Vector3 movementDirection = new Vector3(Input.GetAxis("Horizontal"), 0, Input.GetAxis("Vertical")) * runSpeed * Time.deltaTime;


            transform.LookAt(transform.position + movementDirection);

            // Apply movement
            _controller.Move(movementDirection);
        }   
    }

    public void CollectItem()
    {
        _collectedItems++;
        runSpeed += 5f;
        text.text = "Collected Items: " + _collectedItems + "\nTime: " + _time;
    }

    private IEnumerator Countdown()
    {
        while (_time > 0)
        {
            yield return new WaitForSeconds(1f);
            _time--;
            text.text = "Collected Items: " + _collectedItems + "\nTime: " + _time + "s";
        }

        text.text = "Game Over!\nCollected Items: " + _collectedItems;

        Time.timeScale = 0;
    }
}
