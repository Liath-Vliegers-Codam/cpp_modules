
function showFileName() {
    const fileInput = document.getElementById('file-input');
    const fileInfo = document.getElementById('file-info');
    const fileName = document.getElementById('file-name');
    
    if (fileInput.files.length > 0) {
        fileName.textContent = `Selected: ${fileInput.files[0].name}`;
        fileInfo.style.display = 'block';
    } else {
        fileInfo.style.display = 'none';
    }
}



function formatDate(day, month, date, hour, minute) {
    let now = new Date();
    let days = [
      "Sunday",
      "Monday",
      "Tuesday",
      "Wednesday",
      "Thursday",
      "Friday",
      "Saturday"
    ];
    let months = [
      "January",
      "February",
      "March",
      "April",
      "May",
      "June",
      "July",
      "August",
      "September",
      "October",
      "November",
      "December"
    ];
    day = days[now.getDay()];
    month = months[now.getMonth()];
    date = now.getDate();
  
    hour = now.getHours();
    minute = now.getMinutes();
    if (minute < 10) {
      minute = "0" + minute;
    }
  
    return `${day} | ${month} ${date} | ${hour}:${minute}`;
}
  
let dateAndTime = document.querySelector("#date-and-time");
dateAndTime.innerHTML = formatDate(new Date());