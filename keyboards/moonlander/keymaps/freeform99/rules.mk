# Set any rules.mk overrides for your specific keymap here.
# See rules at https://docs.qmk.fm/#/config_options?id=the-rulesmk-file
AUDIO_ENABLE = no
CAPS_WORD_ENABLE = yes

KEY_OVERRIDE_ENABLE = yes

#https://getreuer.info/posts/keyboards/select-word/index.html
SRC += features/select_word.c
