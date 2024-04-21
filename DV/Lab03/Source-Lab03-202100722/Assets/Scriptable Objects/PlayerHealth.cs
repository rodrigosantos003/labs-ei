using System.Collections.Generic;
using UnityEngine;

[CreateAssetMenu(fileName = "PlayerHealth", menuName = "Scriptable Objects/Player Health")]
public class PlayerHealth : ScriptableObject
{
    private int _value;
    [SerializeField] private int _initialValue;
    [SerializeField] private int _lowValue;


    public delegate void ChangedValue();
    [SerializeField] private List<ChangedValue> _listeners = new List<ChangedValue>();

    public void AddListener(ChangedValue listener)
    {
        _listeners.Add(listener);
    }

    public int LowValue => _lowValue;

    public int Value
    {
        get => _value;
        set  {
            _value = value;
            CallDelegates();
        }
    }

    private void CallDelegates()
    {
        foreach (var listener in _listeners)
        {
            listener.Invoke();
        }
    }

    private void OnEnable()
    {
        _value = _initialValue;
    }
}
