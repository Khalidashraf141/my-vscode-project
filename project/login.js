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
// 🚨 DUMMY DOMAIN CONFIGURATION 
// IMPORTANT: This MUST match the domain you used to create the user 
// in the Firebase Console (e.g., 'admin@yoursiteaccess.com').
// ====================================================================
const DUMMY_DOMAIN = 'khalidashraf141.github.io'; 

// Initialize Firebase App and Authentication Service (using 'compat' method)
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
    // Fetches the content from content.html
    fetch('content.html')
        .then(response => response.text())
        .then(html => {
            // Replaces the body of content.html (everything between <body>...</body>)
            // This prevents duplicate <html>, <head>, and <body> tags
            const bodyContentMatch = html.match(/<body>(.*)<\/body>/s);
            if (bodyContentMatch && bodyContentMatch.length > 1) {
                protectedContentDiv.innerHTML = bodyContentMatch[1];
            } else {
                protectedContentDiv.innerHTML = html; // Fallback
            }
            
            protectedContentDiv.style.display = 'block'; 
            
            // Set up the Logout button listener after content is loaded
            const logoutButton = document.getElementById('logout-button');
            if (logoutButton) {
                logoutButton.addEventListener('click', () => { 
                    auth.signOut(); 
                });
            }
        });
}

function handleLogin() {
    const username = document.getElementById('username').value.trim();
    const password = document.getElementById('password').value;
    errorMessage.textContent = ''; 

    // Append the dummy domain to the entered username for Firebase
    const syntheticEmail = username + DUMMY_DOMAIN;

    auth.signInWithEmailAndPassword(syntheticEmail, password)
        .catch((error) => {
            let message = "Login Failed: Invalid Username or Password.";
            errorMessage.textContent = message;
            // Optionally log the full error for debugging
            console.error("Login Error:", error.message);
        });
}

// ====================================================================
// 3. MAIN AUTH STATE LISTENER (The Magic)
// ====================================================================

auth.onAuthStateChanged((user) => {
    if (user) {
        // Logged In: Hide Form and Show Content
        loginForm.style.display = 'none'; 
        loadProtectedContent();           
    } else {
        // Logged Out: Show Login Form and Clear Content
        loginForm.style.display = 'block';     
        protectedContentDiv.style.display = 'none'; 
        protectedContentDiv.innerHTML = '';    
    }
});

// Attach event listener to the login button
loginButton.addEventListener('click', handleLogin);