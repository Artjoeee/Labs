import { createSlice, createAsyncThunk, PayloadAction } from "@reduxjs/toolkit";
import { Post, NewPost } from "./types";
import * as postsAPI from "./postsAPI";

interface PostsState {
  posts: Post[];
  loading: boolean;
  error: string | null;
}

const initialState: PostsState = {
  posts: [],
  loading: false,
  error: null,
};

export const fetchPosts = createAsyncThunk("posts/fetchPosts", postsAPI.fetchPosts);

export const createNewPost = createAsyncThunk("posts/createPost", postsAPI.createPost);

export const updateExistingPost = createAsyncThunk("posts/updatePost", postsAPI.updatePost);

export const deleteExistingPost = createAsyncThunk("posts/deletePost", async (id: number) => {
  await postsAPI.deletePost(id);
  return id;
});

const postsSlice = createSlice({
  name: "posts",
  initialState,
  reducers: {},
  extraReducers: (builder) => {
    builder
      .addCase(fetchPosts.pending, (state) => {
        state.loading = true;
      })
      .addCase(fetchPosts.fulfilled, (state, action: PayloadAction<Post[]>) => {
        state.loading = false;
        state.posts = action.payload;
      })
      .addCase(fetchPosts.rejected, (state, action) => {
        state.loading = false;
        state.error = action.error.message ?? "Failed to fetch posts";
      })

      .addCase(createNewPost.fulfilled, (state, action: PayloadAction<Post>) => {
        state.posts.unshift(action.payload);
      })

      .addCase(updateExistingPost.fulfilled, (state, action: PayloadAction<Post>) => {
        const index = state.posts.findIndex((p) => p.id === action.payload.id);
        if (index !== -1) state.posts[index] = action.payload;
      })

      .addCase(deleteExistingPost.fulfilled, (state, action: PayloadAction<number>) => {
        state.posts = state.posts.filter((post) => post.id !== action.payload);
      });
  },
});

export default postsSlice.reducer;
