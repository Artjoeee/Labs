var swiper = new Swiper(".product-slider", {
  loop: true,
  spaceBetween: 20,
  centeredSlides: true,
  breakpoints: {
      0: {
          slidesPerView: 1,
      },
      768: {
          slidesPerView: 2,
      },
      1020: {
          slidesPerView: 3,
      },
  },
  scrollbar: {
      el: ".swiper-scrollbar",
      draggable: true,
      freeMode: true,
  },
});


var swiper = new Swiper(".review-slider", {
  loop: true,
  spaceBetween: 20,
  centeredSlides: true,
  breakpoints: {
    0: {
      slidesPerView: 1,
    },
    768: {
      slidesPerView: 2,
    },
    1020: {
      slidesPerView: 3,
    },
  },
  scrollbar: {
    el: ".swiper-scrollbar",
    draggable: true,
    freeMode: true,
},
});