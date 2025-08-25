import React from "react";
import Posts from "./features/posts/Posts";
import PostForm from "./components/PostForm";

const App: React.FC = () => (
  <div>
    <h1>Post Manager</h1>
    <PostForm />
    <Posts />
  </div>
);

export default App;
