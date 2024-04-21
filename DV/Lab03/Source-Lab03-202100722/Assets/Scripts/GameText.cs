using TMPro;
using UnityEngine;

public class GameText : MonoBehaviour
{
    [SerializeField] private PlayerHealth playerHealth;
    [SerializeField] private PlayerController playerController;

    private TextMeshProUGUI _text;

    // Update text on screen
    public void UpdateText()
    {
        _text.text = "Health: " + playerHealth.Value.ToString() +
                     "\nObjects collected: " + playerController.CollectedObjects.ToString() +
                     "\nTimer: " + FormatTime(playerController.Timer);

        if (playerHealth.Value <= 0 || playerController.Timer <= 0f)
        {
            _text.text = "Game Over";
        }

        if(playerController.CollectedObjects == playerController.ObjectsToCollect)
        {
            _text.text = "You Win!";
        }
    }   

    // Start is called before the first frame update
    void Start()
    {
        _text = GetComponent<TextMeshProUGUI>();
        _text.text = playerHealth.Value.ToString() + "\nObjects collected: 0" + "\nTimer: 0:00";
        playerHealth.AddListener(UpdateText);
    }

    // Update is called once per frame
    void Update()
    {
        
    }

    // Format time in minutes and seconds
    private string FormatTime(float timeInSeconds)
    {
        int minutes = Mathf.FloorToInt(timeInSeconds / 60);
        int seconds = Mathf.FloorToInt(timeInSeconds % 60);
        return string.Format("{0:0}:{1:00}", minutes, seconds);
    }
}
