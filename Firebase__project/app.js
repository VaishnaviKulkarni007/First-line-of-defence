// app.js

// Function to display data from Firebase
function displayData(snapshot) {
  const dataContainer = document.getElementById("data-container");
  dataContainer.innerHTML = ""; // Clear previous data

  snapshot.forEach((childSnapshot) => {
    const data = childSnapshot.val();
    const dataElement = document.createElement("p");
    dataElement.textContent = `Distance: ${data.distance} cm, Intervention: ${data.intervention}`;
    dataContainer.appendChild(dataElement);
  });
}

// Function to handle errors
function handleError(error) {
  console.error("Error fetching data:", error);
}

// Function to fetch data from Firebase and display it
function fetchData() {
  const dataRef = firebase.database().ref("restricted_area_data");
  dataRef.on("value", displayData, handleError);
}

// Fetch data when the page loads
document.addEventListener("DOMContentLoaded", fetchData);

// Manually refresh data on button click
const refreshButton = document.getElementById("refresh-button");
refreshButton.addEventListener("click", fetchData);
