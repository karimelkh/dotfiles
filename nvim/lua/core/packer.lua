-- This file can be loaded by calling `lua require('plugins')` from your init.vim

-- Only required if you have packer configured as `opt`
vim.cmd [[packadd packer.nvim]]

return require('packer').startup(function(use)
	-- Packer can manage itself
	use { 'wbthomason/packer.nvim' }

	-- fzf
	use {
		'nvim-telescope/telescope-fzf-native.nvim',
		run = 'make'
	}

	-- rose-pine colorscheme
--	use({
--		'rose-pine/neovim',
--		as = 'rose-pine',
--		config = function()
--			vim.cmd('colorscheme rose-pine')
--			end
--		})
		use {
			'rose-pine/neovim',
			as = 'rose-pine',
			config = function()
				require('rose-pine').setup({
					styles = {
						transparency = true,
					},
				})
				vim.cmd('colorscheme rose-pine')
			end
		}

		-- onedark colorscheme
		-- use 'navarasu/onedark.nvim'
		-- vim.cmd("colorscheme onedark")
		-- require('onedark').setup { style = 'warmer' }
		-- require('onedark').load()

		-- nvim tree
		use {
			'nvim-tree/nvim-tree.lua',
			requires = { 'nvim-tree/nvim-web-devicons' },
		}

		-- lualine status bar
		use {
			'nvim-lualine/lualine.nvim',
			requires = { 'nvim-tree/nvim-web-devicons', opt = true }
		}

		use { 'PeterRincker/vim-searchlight' }
		use { 'google/vim-searchindex' }

		-- startup screen
		--[[ use {
			"startup-nvim/startup.nvim",
			requires = { "nvim-telescope/telescope.nvim", "nvim-lua/plenary.nvim" },
			config = function()
				require"startup".setup()
			end
		}
		require("startup").setup({theme = "evil"})
		]]--

		-- dashboard
		use {
			'nvimdev/dashboard-nvim',
			event = 'VimEnter',
			config = function()
				require('dashboard').setup {
					-- config
				}
			end,
			requires = {'nvim-tree/nvim-web-devicons'}
		}

		-- gitsigns
		use { 'lewis6991/gitsigns.nvim' }

		-- treesitter
		use (
			'nvim-treesitter/nvim-treesitter',
			{ run = ':TSUpdate' }
		)
		use { 'nvim-treesitter/playground' }

		-- lsp-zero
		use {
			'VonHeikemen/lsp-zero.nvim',
			branch = 'v3.x',
			requires = {
				--- Uncomment the two plugins below if you want to manage the language servers from neovim
				-- {'williamboman/mason.nvim'},
				-- {'williamboman/mason-lspconfig.nvim'},

				{'neovim/nvim-lspconfig'},
				{'hrsh7th/nvim-cmp'},
				{'hrsh7th/cmp-nvim-lsp'},
				{'L3MON4D3/LuaSnip'},
			}
		}

		-- mason
		--[[
		use {
			'williamboman/mason.nvim',
			'williamboman/mason-lspconfig.nvim',
		}
		]]--

		use { 'vimwiki/vimwiki' }

end)
