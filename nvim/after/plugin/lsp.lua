local lsp = require('lsp-zero')

lsp.on_attach(function(client, bufnr)
	-- see :help lsp-zero-keybindings
	-- to learn the available actions
	lsp.default_keymaps({buffer = bufnr})
end)


require('lspconfig').clangd.setup({})

-- lsp.set_preferences({
-- 	sign_icons = { }
-- })

--[[
require('mason').setup({})

require('mason-lspconfig').setup({
	ensure_installed = {},
	handlers = {
		function(clangd)
			require('lspconfig').clangd.setup({})
		end,
	},
})
]]--
