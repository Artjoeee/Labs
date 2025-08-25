import React, { useState } from "react";
import { Post } from "../features/posts/types";
import { useAppDispatch } from "../hooks";
import { deleteExistingPost, updateExistingPost } from "../features/posts/postsSlice";

interface Props {
  post: Post;
}

const PostItem: React.FC<Props> = ({ post }) => {
  const dispatch = useAppDispatch();
  const [isEditing, setIsEditing] = useState(false);
  const [title, setTitle] = useState(post.title);
  const [body, setBody] = useState(post.body);

  const handleSave = () => {
    dispatch(updateExistingPost({ ...post, title, body }));
    setIsEditing(false);
  };

  return (
    <div className={`post ${isEditing ? 'editing' : ''}`}>
      {isEditing ? (
        <>
          <input value={title} onChange={(e) => setTitle(e.target.value)} />
          <textarea value={body} onChange={(e) => setBody(e.target.value)} />
          <button onClick={handleSave}>Save</button>
        </>
      ) : (
        <>
          <h3>{post.title}</h3>
          <p>{post.body}</p>
          <button onClick={() => setIsEditing(true)}>Редактировать</button>
          <button onClick={() => dispatch(deleteExistingPost(post.id))}>Удалить</button>
        </>
      )}
    </div>
  );
};

export default PostItem;
