using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;

public class NetworkManScript : Photon.PunBehaviour
{
    #region Public Vars

    public PhotonLogLevel LogLevel = PhotonLogLevel.Informational;
    public byte MaxPlayersPerRoom;

    #endregion

    [SerializeField] private Transform spawnPoint;

    private string _gameVersion = "0.1";
    private string _roomName = "MVRK";


    #region Mono CallBacks

    private void Awake()
    {
        PhotonNetwork.autoJoinLobby = false;
        PhotonNetwork.automaticallySyncScene = true;
        PhotonNetwork.logLevel = LogLevel;

        MaxPlayersPerRoom = 4;
    }
    void Start()
    {
        Connect();
    }


    #endregion

    #region Punbehavior CallBacks

    public override void OnConnectedToMaster()
    {
        base.OnConnectedToMaster();
        Debug.Log("Joining Random Room ###");
        PhotonNetwork.JoinRandomRoom();
    }

    public override void OnDisconnectedFromPhoton()
    {
        base.OnDisconnectedFromPhoton();
        Debug.LogWarning("Someone has left the network");
    }

    public override void OnPhotonRandomJoinFailed(object[] codeAndMsg)
    {
        base.OnPhotonRandomJoinFailed(codeAndMsg);
        Debug.LogWarning("Random room joining failed");
        PhotonNetwork.CreateRoom(_roomName, new RoomOptions() { MaxPlayers = MaxPlayersPerRoom }, null);
    }

    public override void OnCreatedRoom()
    {
        base.OnCreatedRoom();
        Debug.Log("##########SUCCESS#############");

    }
    public override void OnJoinedRoom()
    {
        base.OnJoinedRoom();

        if (SceneManager.GetActiveScene().name == "VR")
        {
            PhotonNetwork.Instantiate("Cube", spawnPoint.position, Quaternion.identity, 0);
            Debug.Log("Player: " + PhotonNetwork.playerName + " has joined room name: " + PhotonNetwork.room.Name);
        }
    }
    #endregion

    #region Public Methods

    public void Connect()
    {
        if (PhotonNetwork.connected)
        {
            Debug.Log("Photon connected attempting to join room");
            PhotonNetwork.JoinRoom(_roomName);
        }
        else
        {
            Debug.Log("Photon not connected attempting to connect using settings");
            PhotonNetwork.ConnectUsingSettings(_gameVersion);
        }
    }

    #endregion
}
