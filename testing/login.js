// ====================================================================
// 1. FIREBASE CONFIGURATION (YOUR ACTUAL KEYS)
// ====================================================================
const firebaseConfig = {
    apiKey: "AIzaSyAH8syhtLbWuR50tH2G4EPyh9_yH-Eamfw",
    authDomain: "login-c353e.firebaseapp.com",
    projectId: "login-c353e",
    storageBucket: "login-c353e.firebasestorage.app",
    messagingSenderId: "208274744382",
    appId: "1:208274744382:web:ad96521681ab0729265d6f"
};

// ====================================================================
// 🚨 DUMMY DOMAIN CONFIGURATION (To enable 'username' instead of 'email')
// Ensure you created a user like 'admin@yoursiteaccess.com' in Firebase
// ====================================================================
const DUMMY_DOMAIN = ''; 

// Initialize Firebase App and Authentication Service (using 'compat' method)
// 🚨 CHANGE: We use firebase.initializeApp() instead of import/initializeApp
const app = firebase.initializeApp(firebaseConfig);
const auth = app.auth(); // Access auth service via the initialized app

// DOM Elements
const loginForm = document.getElementById('login-form');
const protectedContentDiv = document.getElementById('protected-content');
const loginButton = document.getElementById('login-button');
const errorMessage = document.getElementById('error-message');

// ====================================================================
// 2. CORE FUNCTIONS
// ====================================================================

function loadProtectedContent() {
    fetch('content.html')
        .then(response => response.text())
        .then(html => {
            protectedContentDiv.innerHTML = html;
            protectedContentDiv.style.display = 'block'; 
            
            const logoutButton = document.getElementById('logout-button');
            if (logoutButton) {
                logoutButton.addEventListener('click', () => { auth.signOut(); });
            }
        });
}

function handleLogin() {
    const username = document.getElementById('username').value.trim();
    const password = document.getElementById('password').value;
    errorMessage.textContent = ''; 

    // Append the dummy domain to the entered username
    const syntheticEmail = username + DUMMY_DOMAIN;

    auth.signInWithEmailAndPassword(syntheticEmail, password)
        .catch((error) => {
            let message = "Login Failed: Invalid Username or Password.";
            errorMessage.textContent = message;
            console.error("Login Error:", error.message);
        });
}

// ====================================================================
// 3. MAIN AUTH STATE LISTENER (The Magic)
// ====================================================================

auth.onAuthStateChanged((user) => {
    if (user) {
        // Logged In: Show Content
        loginForm.style.display = 'none'; 
        loadProtectedContent();           
    } else {
        // Logged Out: Show Login Form
        loginForm.style.display = 'block';     
        protectedContentDiv.style.display = 'none'; 
        protectedContentDiv.innerHTML = '';    
    }
});

// Attach event listener to the login button
loginButton.addEventListener('click', handleLogin);