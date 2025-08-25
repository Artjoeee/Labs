import React, { useState } from "react";
import { useAppDispatch } from "../hooks";
import { createNewPost } from "../features/posts/postsSlice";

const PostForm: React.FC = () => {
  const dispatch = useAppDispatch();
  const [title, setTitle] = useState("");
  const [body, setBody] = useState("");

  const handleSubmit = (e: React.FormEvent) => {
    e.preventDefault();
    dispatch(createNewPost({ title, body, userId: 1 }));
    setTitle("");
    setBody("");
  };

  return (
    <form onSubmit={handleSubmit}>
      <input
        value={title}
        onChange={(e) => setTitle(e.target.value)}
        placeholder="Заголовок"
        required
      />
      <textarea
        value={body}
        onChange={(e) => setBody(e.target.value)}
        placeholder="Содержание"
        required
      />
      <button type="submit">Добавить пост</button>
    </form>
  );
};

export default PostForm;
