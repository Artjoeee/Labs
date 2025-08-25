import React from 'react';
import { BrowserRouter as Router, Routes, Route } from 'react-router-dom';
import SignUp from './components/signUp';
import SignIn from './components/signIn';
import ResetPassword from './components/resetPassword';


export default function App() {
  return (
    <Router>
      <Routes>
        <Route path="/sign-up" element={<SignUp />} />
        <Route path="/sign-in" element={<SignIn />} />
        <Route path="/reset-password" element={<ResetPassword />} />
        <Route path="*" element={<SignIn />} />
      </Routes>
    </Router>
  );
}
